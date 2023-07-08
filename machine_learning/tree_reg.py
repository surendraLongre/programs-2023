import numpy
from matplotlib import pyplot
import pandas
from sklearn.tree import DecisionTreeRegressor

#dataset
dataset=pandas.read_csv("Position_Salaries.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1].values

#regressor
regressor=DecisionTreeRegressor(random_state=0)
regressor.fit(x,y)

#predicting
result=regressor.predict([[6.5]])
print(result)

#plot
pyplot.plot(x,regressor.predict(x), color='red')
pyplot.scatter(x,y, color='blue')
pyplot.show()
