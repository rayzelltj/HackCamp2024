import React, { useState } from 'react';
import './App.css';


// const handleInfoRecieved = (event) => {
//   if (someBoolean) {
//     setLoading(false);
//     setResponse(true);
//   }
// };

const TextBox = ({ loading, setLoading }) => {
  const [text, setText] = useState("");

  const handleChange = (event) => {
    setText(event.target.value); 
  };

  const handleKeyDown = (event) => {
    if (event.key === 'Enter' && text.trim() !== "") {
      setLoading(true);
      // Simulate loading or navigate to another page here
      // e.g., window.location.href = `/newpage?query=${encodeURIComponent(text)}`;
    }
  };

  if (loading) return null; // Do not render if loading is true

  return (
    <div className="TextBox">
      <input
      type="text"
      id="textBox"
      value={text}
      onChange={handleChange}
      onKeyDown={handleKeyDown}
      className="input-field"
      placeholder='e.g. "I feel dizzy and my chest feels tight"'
      autoFocus
      />
    </div>
  );
};

const Header = ({ loading }) => {
  if (loading) return null; // Do not render if loading is true
  return (
    <div className="App-header">
      <h1>MedLex</h1>
      <h2 className="subheader">A symptom interpreter.</h2>
    </div>
  );
};

const Results = ({ response }) => {
  if (!response) return null; // Do not render if loading is true
  return (
    <div className="App-header">
      
    </div>
  );
};

function App() {
  const [loading, setLoading] = useState(false);
  const [response, setResponse] = useState(false);

  const handleInfoRecieved = (event) => {
    if (false) { //insert some variable from backend
      setLoading(false);
      setResponse(true);
    }
  };

  return (
    <div className="App">
      
      {response ? (
        <>
          <Results response = {response}/>
          <TextBox loading = {loading} setLoading={setLoading} />
        </>
      ) : (
        (loading ? (
          <p className="loading-text">Please give us a moment to analyze</p>
        ) : (
          <>
          <Header loading={loading} />
          <TextBox loading={loading} setLoading={setLoading} />
          </>
        ))
      )}

    </div>
  );
}

export default App;