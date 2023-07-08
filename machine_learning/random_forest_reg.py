import numpy
import pandas
from matplotlib import pyplot
from sklearn.ensemble import RandomForestRegressor

#dataset
dataset=pandas.read_csv("Position_Salaries.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1].values

#training
regressor=RandomForestRegressor(n_estimators=10, random_state=0)
regressor.fit(x,y)

#prediction
result=regressor.predict([[6.5]])
print(result)

#visualizing
pyplot.scatter(x,y,color='red')
pyplot.plot(x,regressor.predict(x),color='blue')
pyplot.show()
