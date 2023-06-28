from matplotlib import pyplot
import pandas
import numpy
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression


#getting the dataset
dataset=pandas.read_csv("Salary_Data.csv")

#get features
x=dataset.iloc[:,:-1].values
y=dataset.iloc[:,-1].values

#splitting into test and train
x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2, random_state=0)

#getting the model
regressor=LinearRegression()
regressor.fit(x_train,y_train)

y_pred=regressor.predict(x_test)


#plotting the plot
pyplot.scatter(x_train,y_train,color='red')
pyplot.plot(x_train,regressor.predict(x_train), color='blue')
pyplot.title("training data")
pyplot.xlabel('yoe')
pyplot.ylabel('salary')
pyplot.show()

pyplot.scatter(x_test,y_test,color='red')
pyplot.plot(x_test,regressor.predict(x_test), color='blue')
pyplot.title("training data")
pyplot.xlabel('yoe')
pyplot.ylabel('salary')
pyplot.show()


