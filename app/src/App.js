import React, { useState } from 'react';
import './App.css';

const TextBox = () => {
  const [text, setText] = useState("");

  // Handles the change event for the input field
  const handleChange = (event) => {
    setText(event.target.value); 
  };

  // Handles the keydown event for the input field
  const handleKeyDown = (event) => {
    if (event.key === 'Enter' && text.trim() !== "") {
      // Change the URL or navigate to a new page
      // Example: Change to your desired URL
      window.location.href = `/newpage?query=${encodeURIComponent(text)}`;
    }
  };

  return (
    <div className="TextBox">
      <input
        type="text"
        id="textBox"
        value={text}          
        onChange={handleChange}
        onKeyDown={handleKeyDown} // Added keydown event listener
        className="input-field"
        placeholder='e.g. "I feel dizzy and my chest feels tight"'
        autoFocus
      />

    </div>
  );
};

const Header = () => {
  return (
    <div className="App-header">
      <h1>MedLex</h1>
      <h2 className="subheader">A symptom interpreter.</h2>
    </div>
  );
};

function App() {
  return (
    <div className="App">
      <Header />
      <TextBox />
    </div>
  );
}

export default App;