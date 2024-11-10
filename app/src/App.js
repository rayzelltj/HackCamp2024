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
      <label htmlFor="TextBox">Enter text: </label>
      <input
        type="text"
        id="textBox"
        value={text}          
        onChange={handleChange}
        placeholder="Type something here..."
      />
      <p>You typed: {text}</p> {}
    </div>
  );
}

const Header = ({ time }) => {
  return (
    <div className="App-header">
      <h1>Symptoms</h1>
    </div>
  );
};

function App() {
  return (
    <div className="App">
      <Header />
      <TextBox />
      <TextBox />
      <TextBox />
    </div>
  );
}

export default App;
