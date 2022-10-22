import React from 'react';
import { useState } from 'react';
import './App.css';
import Navbar from './components/Navbar';
import TextForm from './components/TextForm';

function App() {
  const [mode,setMode] = useState('pink');

  const toggleBtn = () =>{
    if (mode==='pink'){
      setMode('dark')
    }
    else{
      setMode('pink')
    }
  }


  return (
    <>
      <Navbar title="TextUtils" mode = {mode} toggleBtn = {toggleBtn} />
      <TextForm heading="Enter the text below to analyze"/>
    </>
  );
}

export default App;
