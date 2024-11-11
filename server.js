const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');

const app = express();
const PORT = 3000;

app.use(bodyParser.json());

// Endpoint to receive user input and save to input.json
app.post('/process-input', (req, res) => {
  const userInput = req.body.input;

  // Safely resolve the path for input.json in the app directory
  const inputFilePath = path.join(__dirname, 'app', 'input.json');
  
  try {
    // Write user input as a string to input.json
    fs.writeFileSync(inputFilePath, JSON.stringify({ input: userInput }));
    console.log('User input written to input.json');
  } catch (err) {
    console.error('Error writing input.json:', err);
    return res.status(500).json({ error: 'Error writing input.json' });
  }

  // Run HackCamp2024 binary in the model directory
  exec('./HackCamp2024', { cwd: path.join(__dirname, 'model') }, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error: ${error.message}`);
      console.error(`stderr: ${stderr}`);
      return res.status(500).json({ error: "Error running C++ program" });
    }
    console.log(`stdout: ${stdout}`);

    // Send back a success response
    res.json({ success: true });
  });
});

// Endpoint to fetch processed symptoms data
app.get('/symptoms', (req, res) => {
  // Safely resolve the path for symptoms.json in the app/src directory
  const symptomsFilePath = path.join(__dirname, 'app', 'src', 'symptoms.json');

  // Read symptoms.json and send it to the frontend
  fs.readFile(symptomsFilePath, 'utf8', (err, data) => {
    if (err) {
      console.error("Error reading symptoms.json", err);
      return res.status(500).json({ error: "Error reading symptoms.json" });
    }
    res.json(JSON.parse(data));
  });
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});