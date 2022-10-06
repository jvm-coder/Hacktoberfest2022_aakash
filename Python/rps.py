from random import choice

validation = ["Rock","Paper","Scissor"]
rps = [{
	"sign":"Rock",
	"vul":"Paper"
},{"sign":"Paper","vul":"Scissor"},{"sign":"Scissor","vul": "Rock"}]

while True:
	uoptn = str(input("Do You Want To Play Again? [y/n]\n"))
	if uoptn == "y":
		print("Started RPS Game !")
		user_c = str(input("Select [Enter Full Name]\n1.Rock\n2.Paper\n3.Scissor\n>>>"))
		bot_c = choice(rps)
		if user_c in validation:
			if bot_c["sign"] == user_c.capitalize():
				print(f"Both used same sign ! {user_c}")
			elif bot_c["vul"] == user_c.capitalize():
				print(f"You Win ! Bot used {bot_c['sign']}")
			else:
				print(f"You Lose! Bot used {bot_c['sign']}")
		else:
			print("Invaild Option ! Try Again")
	else:
		print("Closing Game ! Resons\n1. Your Input Was Wrong [other than y]\n2. You Wanted To Close Game !")
		break