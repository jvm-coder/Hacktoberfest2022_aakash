THEME_COLOR = "#375362"

from tkinter import *
from quiz_brain import QuizBrain

class QuizInterface:
    def __init__(self, quiz_brain: QuizBrain):
        self.quiz= quiz_brain

        self.window = Tk()
        self.window.title("Quiz")
        self.window.config(padx=20, pady=20, highlightthickness=0, bg=THEME_COLOR)


        self.score_lable = Label(text="Score:0", fg="white", bg=THEME_COLOR,highlightthickness=0)
        self.score_lable.grid(row=0, column=1)


        self.canvas = Canvas(width=300, height=250, highlightthickness=0, bg="White")
        self.question_text = self.canvas.create_text(150, 125, width=280, text="Question Text", fill=THEME_COLOR, font=("Arial", 20, "italic"))
        self.canvas.grid(row=1, column=0, columnspan=2, pady=50)


        wrong_image = PhotoImage(file="images/false.png")
        self.wrong_button = Button(image=wrong_image, highlightthickness=0, bg=THEME_COLOR,command=self.false_pressed )
        self.wrong_button.grid(row=2, column=0)


        right_image = PhotoImage(file="images/true.png")
        self.right_button = Button(image=right_image, highlightthickness=0, bg=THEME_COLOR, command=self.true_pressed )
        self.right_button.grid(row=2, column=1)

        #card_title = canvas.create_text(150, 207, text="Tital", width=250, font=("Ariel", 40, "italic"))

        self.get_next_question()
        self.window.mainloop()




    def get_next_question(self):
        self.canvas.config(bg="white")
        if self.quiz.still_has_questions():
            self.score_lable.config(text=f"Score: {self.quiz.score}")
            q_text = self.quiz.next_question()
            self.canvas.itemconfig(self.question_text, text=q_text)
        else:
            self.canvas.itemconfig(self.question_text, text="You have reached the end of the quiz")
            self.right_button.config(state="disabled")
            self.wrong_button.config(state="disabled")


    def true_pressed(self):
        self.give_feedback(self.quiz.check_answer("True"))


    def false_pressed(self):
        self.give_feedback(self.quiz.check_answer("False"))

    def give_feedback(self,is_right):
        if is_right:
            self.canvas.config(bg="green")
        else:
            self.canvas.config(bg="red")
        self.window.after(1000,self.get_next_question)