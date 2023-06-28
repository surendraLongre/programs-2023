import pandas
import numpy
from sklearn.impute import SimpleImputer
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder,LabelEncoder, StandardScaler
from sklearn.model_selection import train_test_split

dataset=pandas.read_csv("Data.csv")

#get the features
x=dataset.iloc[:, :-1].values
y=dataset.iloc[:,-1].values

imputer=SimpleImputer(missing_values=numpy.nan, strategy='mean')
imputer.fit(x[:,1:])
x[:,1:]=imputer.transform(x[:,1:])

# encoding categorical data
ct=ColumnTransformer(transformers=[('encoder', OneHotEncoder(), [0])], remainder='passthrough')
x=numpy.array(ct.fit_transform(x))

# label encoding

le=LabelEncoder()
y=le.fit_transform(y)

# splitting

x_train, x_test, y_train, y_test=train_test_split(x,y,test_size=0.2, random_state=1)

print(x_test, y_test)


#feature scaling
sc=StandardScaler()
x_train[:,3:]=sc.fit_transform(x_train[:,3:])
x_test[:,3:]=sc.transform(x_test[:,3:])

print(x_train, x_test)

