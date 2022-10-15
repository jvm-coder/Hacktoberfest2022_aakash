import streamlit as st

from random import randint

t = ["Rock", "Paper", "Scissors"]
computer = t[randint(0, 2)]
title = st.title("Lets play Rock Paper Scissors with computer")
player = False
#player=st.text_input("Rock ,Paper ,Scissors ?")
player = st.selectbox("Rock ,Paper ,Scissors ?", ["Rock", "Paper", "Scissors"])
if (st.button("SUBMIT")):
    if player == computer:
        st.text("Tie!!!")
    elif player == "Rock":
        if computer == "Paper":
            st.text("Player won ^.^")
        else:
            st.text("computer won ^-^ ")
    elif player == "Paper":
        if computer == "Scissors":
            st.text("Computer won ^.^")
        else:
            st.text("Player won ^-^ ")
    elif player == "Scissors":
        if computer == "Rock":
            st.text("Player won ^-^ ")
        else:
            st.text("Computer won ^.^")
    else:
        st.text("Check your spelling --------------------")

    player = False
    computer = t[randint(0, 2)]
