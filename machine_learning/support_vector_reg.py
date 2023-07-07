#importing libraries
import pandas
import numpy
from matplotlib import pyplot
from sklearn.svm import SVR
from sklearn.preprocessing import OneHotEncoder,LabelEncoder, StandardScaler

#import dataset
dataset=pandas.read_csv("Position_Salaries.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1].values

#transformation of y to 2D array
y=y.reshape(len(y),1)

#feature scaling
sc_x=StandardScaler()
sc_y=StandardScaler()

x=sc_x.fit_transform(x)
y=sc_y.fit_transform(y)

#training
regressor=SVR(kernel='rbf')

regressor.fit(x,y)
result=sc_y.inverse_transform(regressor.predict(sc_x.transform([[6.5]])).reshape(-1,1))

#plotting

pyplot.title('level vs salary')
pyplot.scatter(sc_x.inverse_transform(x),sc_y.inverse_transform(y),color='red')
pyplot.xlabel('salary')
pyplot.ylabel('level')
pyplot.plot(sc_x.inverse_transform(x),sc_y.inverse_transform(regressor.predict(x).reshape(-1,1)),color='blue')
pyplot.show()

