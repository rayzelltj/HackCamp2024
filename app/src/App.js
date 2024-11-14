import React, { useState } from 'react';
// import symptoms from './symptoms.json';
import './App.css';
import steth from './logoicon.png';

const BASE_URL = 'http://localhost:3000';

// const handleInfoRecieved = (event) => {
//   if (someBoolean) {
//     setLoading(false);
//     setResponse(true);
//   }
// };

const TextBox = ({ loading, setLoading, setResponse }) => {
  const [text, setText] = useState("");

  const handleChange = (event) => {
    setText(event.target.value); 
  };

  const handleKeyDown = async (event) => {
    if (event.key === 'Enter' && text.trim() !== "") {
      setLoading(true);
      setResponse(null);
      await processInput(text);
      const symptomsData = await fetchSymptoms();
      setTimeout(() => {
        setResponse(symptomsData);
        setLoading(false);
      }, 3000);
      // Simulate loading or navigate to another page here
      // e.g., window.location.href = `/newpage?query=${encodeURIComponent(text)}`;
    }
  };


async function processInput(input) {
  const response = await fetch(`/process-input`, {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ input }),
  });
  return response.json();
}

async function fetchSymptoms() {
  const response = await fetch(`/symptoms`);
  return response.json();
}

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
      <div className="header-content">
        <h1>MedLex</h1>
        <img src={steth} alt="steth" className="steth" />
      </div>
      <h2 className="subheader">A symptom interpreter.</h2>
    </div>
  );
};

const Results = ({ response }) => {
  if (!response) return null; // Do not render if loading is true
  return (
    <div className="App-header">
      <ul>
        {Object.entries(response).map(([key, value]) => (
          <li key={key}>
            {key} : {value}
          </li>
        ))}
      </ul>
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
          <TextBox loading = {loading} setLoading={setLoading} setResponse={setResponse} />
        </>
      ) : (
        (loading ? (
          <p className="loading-text">Please give us a moment to analyze</p>
        ) : (
          <>
          <Header loading={loading} />
          <TextBox loading={loading} setLoading={setLoading} setResponse={setResponse} />
          </>
        ))
      )}

    </div>
  );
}

export default App;