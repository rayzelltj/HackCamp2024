const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const path = require('path');
const { exec } = require('child_process');

const app = express();
const PORT = 3000;

app.use(bodyParser.json());

// Receive user input and save it to input.json
app.post('/process-input', (req, res) => {
  const userInput = req.body.input;
  const inputFilePath = path.join(__dirname, 'app', 'input.json');
  
  fs.writeFileSync(inputFilePath, JSON.stringify(userInput));
  console.log('User input written to input.json');

  // Run HackCamp2024 binary
  exec('./HackCamp2024', { cwd: path.join(__dirname, 'model') }, (stdout) => {
    console.log(`stdout: ${stdout}`);
    res.json({ success: true });
  });
});

// Fetch processed symptoms data
app.get('/symptoms', (req, res) => {
  const symptomsFilePath = path.join(__dirname, 'app', 'symptoms.json');

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