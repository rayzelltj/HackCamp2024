import React, { useState } from 'react';
import './App.css';

const TextBox = () => {
  const [text, setText] = useState("");
  const handleChange = (event) => {
    setText(event.target.value); 
  };

  return (
    <div className="TextBox">
      <input
        type="text"
        id="textBox"
        value={text}          
        onChange={handleChange}
        className="input-field"
        placeholder='e.g. "My head is painful and my eyes feel tired"'
        autoFocus
      />
      <button className="search-button">🔍</button>
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