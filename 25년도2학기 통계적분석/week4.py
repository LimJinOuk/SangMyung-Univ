import numpy as np
import pandas as pd

df = pd.read_csv('../pyst/data/ch2_scores_em.csv',
                 index_col='student number')

en_scores = np.array(df['english'])[:10]
ma_scores = np.array(df['mathematics'])[:10]

scores_df = pd.DataFrame({'english': en_scores,'mathematics': ma_scores},index=pd.Index(['A', 'B', 'C', 'D', 'E','F', 'G', 'H', 'I', 'J'],name='student'))

scores_df

summary_df = scores_df.copy()
summary_df['english_deviation'] = \
    summary_df['english'] - summary_df['english'].mean()
summary_df['mathematics_deviation'] = \
    summary_df['mathematics'] - summary_df['mathematics'].mean()
summary_df['product of deviations'] = \
    summary_df['english_deviation'] * summary_df['mathematics_deviation']
summary_df

summary_df['product of deviations'].mean()

cov_mat = np.cov(en_scores, ma_scores, ddof=0)
cov_mat

cov_mat[0, 0], cov_mat[1, 1]

np.var(en_scores, ddof=0), np.var(ma_scores, ddof=0)

cov_mat[0, 1], cov_mat[1, 0]

np.cov(en_scores, ma_scores, ddof=0)[0, 1] / \
    (np.std(en_scores, ddof=0) * np.std(ma_scores, ddof=0))

np.corrcoef(en_scores, ma_scores)

scores_df.corr()

import matplotlib.pyplot as plt

english_scores = np.array(df['english'])
math_scores = np.array(df['mathematics'])

fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111)
ax.scatter(english_scores, math_scores)
ax.set_xlabel('english')
ax.set_ylabel('mathematics')

plt.show()

poly_fit = np.polyfit(english_scores, math_scores, 1)
poly_1d = np.poly1d(poly_fit)
xs = np.linspace(english_scores.min(), english_scores.max())
ys = poly_1d(xs)

fig = plt.figure(figsize=(8, 8))
ax = fig.add_subplot(111)
ax.set_xlabel('english')
ax.set_ylabel('mathematics')
ax.scatter(english_scores, math_scores, label='score')
ax.plot(xs, ys, color='gray', label=f'{poly_fit[1]:.2f}+{poly_fit[0]:.2f}x')
ax.legend(loc='upper left')

plt.show()

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111)

c = ax.hist2d(english_scores, math_scores, bins=[9, 8], range=[(35, 80), (55, 95)])
ax.set_xlabel('english')
ax.set_ylabel('mathematics')
ax.set_xticks(c[1])
ax.set_yticks(c[2])
fig.colorbar(c[3], ax=ax)

plt.show()

anscombe_data = np.load('../pyst/data/ch3_anscombe.npy')
print(anscombe_data.shape)
anscombe_data[0]

stats_df = pd.DataFrame(index=['X_mean', 'X_variance', 'Y_mean', 'Y_variance', 'X&Y_correlation','X&Y_regression line'])

for i, data in enumerate(anscombe_data):
    dataX = data[:, 0]
    dataY = data[:, 1]
    poly_fit = np.polyfit(dataX, dataY, 1)
    stats_df[f'data{i+1}'] = [
        f'{np.mean(dataX):.2f}',
        f'{np.var(dataX):.2f}',
        f'{np.mean(dataY):.2f}',
        f'{np.var(dataY):.2f}',
        f'{np.corrcoef(dataX, dataY)[0, 1]:.2f}',
        f'{poly_fit[1]:.2f}+{poly_fit[0]:.2f}x'
    ]

stats_df

fig, axes = plt.subplots(nrows=2, ncols=2, figsize=(10, 10), sharex=True, sharey=True)

xs = np.linspace(0, 30, 100)
for i, data in enumerate(anscombe_data):
    poly_fit = np.polyfit(data[:, 0], data[:, 1], 1)
    poly_1d = np.poly1d(poly_fit)
    ys = poly_1d(xs)
    ax = axes[i // 2, i % 2]
    ax.set_xlim([4, 20])
    ax.set_ylim([3, 13])
    ax.set_title(f'data{i+1}')
    ax.scatter(data[:, 0], data[:, 1])
    ax.plot(xs, ys, color='gray')

plt.tight_layout()
plt.show()

df = pd.read_csv('../pyst/data/ch4_scores400.csv')
scores = np.array(df['score'])
scores[:10]

np.random.choice([1, 2, 3], 3)

np.random.choice([1, 2, 3], 3, replace=False)

np.random.seed(0)
np.random.choice([1, 2, 3], 3)

np.random.seed(0)
sample = np.random.choice(scores, 20)
sample.mean()

scores.mean()

for i in range(5):
    sample = np.random.choice(scores, 20)
    print(f'{i+1}번째 무작위 추출로 얻은 표본평균:', sample.mean())
