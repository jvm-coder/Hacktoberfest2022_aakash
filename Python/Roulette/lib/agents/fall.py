from stable_baselines.common.vec_env import DummyVecEnv
from stable_baselines import DQN, PPO2, A2C, ACER
import stable_baselines
from lib.env.roulette import datares_roulette
import os

def train_dqn(timesteps, name):
    env = datares_roulette
    env = DummyVecEnv([env])
    model = DQN(stable_baselines.deepq.policies.MlpPolicy, env, verbose=1,)
    model.learn(total_timesteps=timesteps)
    model.save(name)
    return model
def train_a2c(timesteps, name):
    env = datares_roulette
    env = DummyVecEnv([env])
    model = A2C(stable_baselines.common.policies.MlpPolicy, env, verbose=1,)
    model.learn(total_timesteps=timesteps)
    model.save(name)
    return model
def train_acer(timesteps, name):
    env = datares_roulette
    env = DummyVecEnv([env])
    model = ACER(stable_baselines.common.policies.MlpPolicy, env, verbose=1,)
    model.learn(total_timesteps=timesteps)
    model.save(name)
    return model
def train_ppo(timesteps, name):
    env = datares_roulette
    env = DummyVecEnv([env])
    model = PPO2(stable_baselines.common.policies.MlpPolicy, env, verbose=1,)
    model.learn(total_timesteps=timesteps)
    model.save(name)
    return model

def test_ppo(name):
    model_path = os.path.join('models', name)
    model = PPO2.load(model_path)
    return model
def test_dqn(name):
    model_path = os.path.join('models', name)
    model = DQN.load(model_path)
    return model
def test_a2c(name):
    model_path = os.path.join('models', name)
    model = A2C.load(model_path)
    return model
def test_acer(name):
    model_path = os.path.join('models', name)
    model = ACER.load(model_path)
    return model