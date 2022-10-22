import React, { useState } from "react";


export default function TextForm(props) {
  const upperCase = () => {
      setText(text.toUpperCase())
  }

  const lowerCase = () => {
    setText(text.toLowerCase())
}

const clearText = () => {
  setText('')
  document.getElementById('myBox').value = "";
}

  const handleOnChange= (event) => {
      console.log("Handle on change")
      setText(event.target.value)
  } 
  const [text,setText] = useState('');

  return (
    <div className="container">
      <div className="mb-3 my-3">
        <h1 className="text-center">
            {props.heading}
        </h1>
        
        <textarea className="form-control" onChange={handleOnChange} id="myBox" rows="5"></textarea>
        <div className="text-center">
        <button className="btn btn-pink m-3" onClick={upperCase}>Convert to uppercase</button>
        <button className="btn btn-pink m-3" onClick={lowerCase}>Convert to lowercase</button>
        <button className="btn btn-pink m-3" onClick={clearText}>Clear Text</button>
        <p className="">Word Count : {text.split(' ').filter(function(n){return (n !== '')}).length} & Characters : {text.length}</p>
        <p>Time in minutes : {(0.008 * text.split(' ').filter(function(n){return (n !== '').length).toFixed(3)}</p>
        </div>
        <div className="form-control preview">{text}</div>
      </div>
    </div>

    
  );
}
