console.log("Hello Javascript");
showNotes();

// If user adds a note, add it to the localStorage
let addBtn = document.getElementById('addBtn');
addBtn.addEventListener('click',function(){

    let addTxt = document.getElementById('addTxt');
    let notes = localStorage.getItem("notes");
    if(notes==null){
        noteObj = [];
    }
    else{
        noteObj = JSON.parse(notes);
    }
    noteObj.push(addTxt.value);
    localStorage.setItem("notes",JSON.stringify(noteObj));
    addTxt.value = "";
    console.log(noteObj);
    showNotes();

})

// function to show Notes 
function showNotes(){
    let notes = localStorage.getItem("notes");
    if(notes==null){
        noteObj = [];
    }
    else{
        noteObj = JSON.parse(notes);
    }

    let html = "";
    noteObj.forEach(function(element,index){
        html += `<div class="noteCard my-2 mx-2 card" style="width: 18rem;">
                    <div class="card-body">
                        <h5 class="card-title">Note ${index+1}</h5>
                        <p class="card-text">${element}</p>
                        <button id="${index}" onclick="deleteNote(this.id)" class="btn btn-primary">Delete Note</button>
                    </div>
                </div>`;
    });

    let notesElm = document.getElementById('notes');
    if(noteObj.length!=0){
          notesElm.innerHTML = html;
    }
    else{
        notesElm.innerHTML = `Nothing to show! Use "Write a Note" section above to add notes.`;
    }

}


// function to delete a note

function deleteNote(index){
    console.log("I am deleting",index);
    let notes = localStorage.getItem("notes");
    if(notes==null){
        noteObj = [];
    }
    else{
        noteObj = JSON.parse(notes);
    }
    noteObj.splice(index,1);
    localStorage.setItem("notes",JSON.stringify(noteObj));
    showNotes();

}



// Function to search Notes

let search = document.getElementById('searchTxt');
search.addEventListener('input',function(){

    let inputVal = search.value.toLowerCase();
    console.log('Input Event Fired');
    let noteCards = document.getElementsByClassName('noteCard');
    Array.from(noteCards).forEach(function(element){
        let cardTxt = element.getElementsByTagName("p")[0].innerText;
        console.log(cardTxt);
        if(cardTxt.includes(inputVal)){
            element.style.display = "block";
        }    
        else{
            element.style.display = "none";

        }

    })
})


// further Feature

// 1) Add Title
// 2) Mark a note as Important
// 3) Separate notes by notes
// 4) Sync and Host to Web Server






