import numpy as np
import pandas as pd

df = pd.read_csv("../data/ch2_scores_em.csv" , index_col='student number')
df.head()

scores = np.array(df['english'])[:10]
scores

scores_df = pd.DataFrame({'scores':scores} , index= pd.Index(['A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J'] , name = 'student'))
scores_df

sum(scores) / len(scores)

np.mean(scores)

scores_df.mean()

sorted_scores = np.sort(scores)
sorted_scores

n = len(sorted_scores)
if n % 2 == 0 :
    m0 = sorted_scores[n//2 - 1]
    m1 = sorted_scores[n//2]
    median = (m0 + m1) / 2
else :
    median = sorted_scores[(n+1)//2 - 1]
median

np.median(scores)
scores_df.median()

pd.Series([1,1,1,2,2,3]).mode()

pd.Series([1,2,3,4,5]).mode()

mean = np.mean(scores)
deviation = scores - mean
deviation

another_scores = [50 , 60 , 58 , 54 , 51 , 57 , 58 , 53 , 52 , 59]
another_mean = np.mean(another_scores)
another_deviation = another_scores - another_mean
another_deviation

np.mean(deviation)
np.mean(another_deviation)

summary_df = scores_df.copy()
summary_df['deviation'] = deviation
summary_df

summary_df.mean()

np.mean(deviation ** 2)
np.var(scores)

scores_df.var()

summary_df['square_of_deviation'] = np.square(deviation)
summary_df

np.sqrt(np.var(scores , ddof=0))
np.std(scores , ddof=0)

np.max(scores) - np.min(scores)
np.int64(28)

scores_Q1 = np.percentile(scores , 25)
scores_Q3 = np.percentile(scores , 75)
scores_IQR = scores_Q3 - scores_Q1
scores_IQR

pd.Series(scores).describe()

z = (scores - np.mean(scores)) / np.std(scores)
z

np.mean(z) , np.std(z , ddof=0)

z = 50 + 10 * (scores - np.mean(scores)) / np.std(scores)
z

scores_df['deviation_value'] = z
scores_df

english_scores = np.array(df['english'])
pd.Series(english_scores).describe()

freq , _ = np.histogram(english_scores , bins=10 , range=(0,100))
freq

freq_class = [f'{i}~{i+10}' for i in range(0 , 100 , 10)]
freq_dist_df = pd.DataFrame({'frequency':freq} , index=pd.Index(freq_class , name='class'))

freq_dist_df

for a in range(7):
    print(a)
    
for a in range(10 , 5 , -1):
    print(a)
    
for a in range(20 , 31 , 2):
    print(a)
    
total = 0
for i in range(1 , 10):
    total = total + i
print(total)

total = 0 
for i in range(1 , 10 , 2):
    total = total + i 
print(total)

class_value = [(i+(i+10))//2 for i in range(0 , 100 , 10)]
class_value

rel_freq = freq / freq.sum()
rel_freq

cum_rel_freq = np.cumsum(rel_freq)
cum_rel_freq

freq_dist_df['class value'] = class_value
freq_dist_df['relative frequency'] = rel_freq
freq_dist_df['cumulative relative frequency'] = cum_rel_freq
freq_dist_df = freq_dist_df[['class value', 'frequency','relative frequency', 'cumulative relative frequency']]

freq_dist_df

import matplotlib.pyplot as plt

fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111)

freq, _, _ = ax.hist(english_scores, bins=10, range=(0, 100))

ax.set_xlabel('score')
ax.set_ylabel('person number')

ax.set_xticks(np.linspace(0, 100, 11))
ax.set_yticks(np.arange(0, freq.max() + 1))

plt.show()

fig = plt.figure(figsize=(10, 6))
ax = fig.add_subplot(111)

freq, _, _ = ax.hist(english_scores, bins=25, range=(0, 100))
ax.set_xlabel('score')
ax.set_ylabel('person number')

ax.set_xticks(np.linspace(0, 100, 25+1))
ax.set_yticks(np.arange(0, freq.max()+1))
plt.show()

fig = plt.figure(figsize=(10, 6))
ax1 = fig.add_subplot(111)
ax2 = ax1.twinx()

weights = np.ones_like(english_scores) / len(english_scores)
rel_freq, _, _ = ax1.hist(english_scores, bins=25, range=(0, 100), weights=weights)

cum_rel_freq = np.cumsum(rel_freq)
class_value = [(i+(i+4))/2 for i in range(0, 100, 4)]

ax2.plot(class_value, cum_rel_freq,ls='-', marker='o', color='gray')

ax2.grid(visible=False)

ax1.set_xlabel('score')
ax1.set_ylabel('relative frequency')
ax2.set_ylabel('cumulative relative frequency')
ax1.set_xticks(np.linspace(0, 100, 25+1))

plt.show()

fig = plt.figure(figsize=(5,6))
ax = fig.add_subplot(111)
ax.boxplot(english_scores , tick_labels = ['english'])

plt.show