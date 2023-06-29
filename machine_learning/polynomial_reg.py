import pandas
import numpy
from matplotlib import pyplot
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures

#get the dataset
dataset=pandas.read_csv("Position_Salaries.csv")
x=dataset.iloc[:,1:-1].values
y=dataset.iloc[:,-1].values


#training linear model on the dataset
lin_reg=LinearRegression()
lin_reg.fit(x,y)


#training polynomial model on the dataset
poly_reg=PolynomialFeatures(4)
x_poly=poly_reg.fit_transform(x)

lin_reg2=LinearRegression()
lin_reg2.fit(x_poly,y)

#visualize the data
#pyplot.scatter(x,y,color='red')
#pyplot.plot(x,lin_reg.predict(x), color='blue')
#pyplot.title('multi linear regression')
#pyplot.xlabel('level')
#pyplot.ylabel('salary')
#pyplot.show()

#pyplot.scatter(x,y,color='red')
#pyplot.plot(x,lin_reg2.predict(poly_reg.fit_transform(x)), color='blue')
#pyplot.title('polynomial')
#pyplot.xlabel('level')
#pyplot.ylabel('salary')
#pyplot.show()

#predicting new salary
#because new employee said he earned 160,000$ in the previous company
#let's check if he is saying truth is just a bluff

#print(lin_reg2.predict([[6.5]]))
print(lin_reg2.predict(poly_reg.fit_transform([[6.5]]))) #predicts 159,000 which is super close to 160,000 therefore, he must be stating truth
