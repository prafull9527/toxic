import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score,mean_squared_error
df=pd.read_csv('/home/ubuntu1/Desktop/nikitah/data.csv') 
df.sample(5)
print(df.shape)
print(df['Make'].value_counts())
new_df=df[df['Make']=='Volkswagen']
print(new_df.shape)
print(new_df.isnull().sum())
new_df=new_df.dropna()
new_df.shape
new_df.isnull().sum()
new_df.sample(2)
new_df=new_df[['Engine HP','MSRP']]
new_df.sample(5)
X=np.array(new_df[['Engine HP']])
y=np.array(new_df[['MSRP']])
print(X.shape)
print(y.shape)

plt.scatter(X,y,color="red")
plt.title('HP vs MSRP')
plt.xlabel('HP')
plt.ylabel('MSRP')
plt.show()

X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.30,random_state=15)

regressor=LinearRegression()
regressor.fit(X_train,y_train)

plt.scatter(X_test,y_test,color="green")
plt.plot(X_train,regressor.predict(X_train),color="red",linewidth=3)
plt.title('Regression(Test Set)')
plt.xlabel('HP')
plt.ylabel('MSRP')
plt.show()

plt.scatter(X_train,y_train,color="blue")
plt.plot(X_train,regressor.predict(X_train),color="red",linewidth=3)
plt.title('Regression(Training Set)')
plt.xlabel('HP')
plt.ylabel('MSRP')
plt.show()

y_pred=regressor.predict(X_test)
print('R2 score:%2f'%r2_score(y_test,y_pred))

print('Mean Error:',mean_squared_error(y_test,y_pred))


