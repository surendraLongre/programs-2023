import pandas
import numpy
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

#getting the dataset
dataset=pandas.read_csv("50_Startups.csv")

x=dataset.iloc[:,:-1].values
y=dataset.iloc[:,-1].values

#change categorical data
ct=ColumnTransformer(transformers=[('encoder', OneHotEncoder(), [-1])], remainder='passthrough')
x=numpy.array(ct.fit_transform(x))

#splitting into test sets
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=0)

#train on the dataset
regressor=LinearRegression()
regressor.fit(x_train,y_train)

#predicting 
y_pred=regressor.predict(x_test)

for i in range(len(y_pred)):
    print(f"y_pred: {y_pred[i]} y_test: {y_test[i]}")
