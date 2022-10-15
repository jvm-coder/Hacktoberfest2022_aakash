import gym
import numpy as np
from gym import spaces
from gym.utils import seeding
import pandas as pd

def combos():
    df = pd.read_csv("combos_7.csv", header=None) 
    return df.iloc[:,:-1].values

class datares_roulette(gym.Env):
	def  __init__(self, spots=37, budget=500):
		self.n = spots +  1
		self.action_space = spaces.Discrete(128)
		self.observation_space = spaces.Box(low=0, high=1000, shape = (9,), dtype=np.int32)
		self.seed()
		self.budget = budget
		self.combos = combos()
	def  seed(self, seed=None):
		self.np_random, seed = seeding.np_random(seed)
		return  [seed]
	def step(self, action):
		if action == 127:
			action = np.array([0,0,0,0,0,0,0])
		else:
			action = np.array(self.combos[action])

		if action.shape == (1, 7):
			action = action[0]
	
		val =  self.np_random.randint(0,  self.n -  1)
		obs = [val, 
			self.budget, 
			val % 2 == 0, 
			val % 2 != 0, 
			val >= 1 and val <= 12, 
			val >= 13 and val <= 24, 
			val >= 25 and val <= 36,
			val >= 1 and val <= 18, 
			val >= 19 and val <= 36]

		reward = 0
		try:
			for i in range(len(obs) - 2):
				if obs[i + 2] and action[i]:
					reward += 1
				if not obs[i + 2] and action[i]:
					reward -= 1
		except: 
			print("error")
			pass

		self.budget = self.budget + reward
		
		obs = [val, 
			self.budget, 
			val % 2 == 0, 
			val % 2 != 0, 
			val >= 1 and val <= 12, 
			val >= 13 and val <= 24, 
			val >= 25 and val <= 36,
			val >= 1 and val <= 18, 
			val >= 19 and val <= 36]

		return  obs, reward, self.budget < 100, {}

	def  reset(self):
		self.budget = 500
		return [0,self.budget,0,0,0,0,0,0,0]
