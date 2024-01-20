import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn import metrics
import seaborn as sn
import matplotlib.pyplot as plt
data=pd.read_csv('data.csv')
x=dataset.iloc[:,[2,3]].values
y=dataset.iloc[:,4].values
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.25,random_state=0)
logistic_regression=LogisticRegression()
logistic_regression.fit(x_train,y_train)
y_pred=logistic_regression.predict(x_test)
confusion_matrix = pd.crosstable(y_test,y_pred,rownames=['Actual'],colnames=['Predicted'])
sn.heatmap(confusion_matrix,annot=True)
print('Accuracy:',matrics.accuracy_score(y_test,y_pred))
plt.show()
print(x_test)
print(y_pred)

