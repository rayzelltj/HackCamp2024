import logo from './logo.svg';
import React, { useState, setText } from 'react';
import './App.css';

const TextBox = () => {
  const [text, setText] = useState("");
  const handleChange = (event) => {
    setText(event.target.value); 
  };

  return (
    <div className = "TextBox">
      <Label/>

      <input
        type="text"
        id="textBox"
        value={text}          
        onChange={handleChange}
        className="input-field"
        placeholder="Type something here..."
        autoFocus
      />
    </div>
  );
}

const Header = () => {
  return (
    <div className="App-header">
      <h1>MedLex</h1>
    </div>
  );
};

const SubHeader = () => {
  return (
    <div className="App-subheader">
      <h1>A symptoms interpreter</h1>
    </div>
  );
};

const Label = () => {
  return (
    <div className="label">
      <h1>Enter Your Symptoms</h1>
    </div>
  );
};

function App() {
  return (
    <div className="App">
      <Header />
      <SubHeader />
      <TextBox />
    </div>
  );
}

export default App;
