import 'package:flutter/material.dart';

void main() {
	runApp(
			MyApp()
	      );
}

class MyApp extends StatelessWidget {
	@override
		Widget build(BuildContext context){
			return MaterialApp(
					home: Scaffold(
						backgroundColor: Colors.teal,
						body: SafeArea(
							child: Center(
								child:Column(
									mainAxisSize:MainAxisSize.min, 
									children:<Widget>[
									CircleAvatar(
										radius:50.0,
										backgroundImage: AssetImage('images/wdp.jpg'),
										),
									Text(
										'KGPK',
										style: TextStyle(
											fontFamily:'Pacifico',
											fontSize:40.0,
											color:Colors.white,
											fontWeight: FontWeight.bold,
											),

									    ),
									SizedBox(height:5.0),
									Text(
										'FLUTTER DEVELOPER',
										style: TextStyle(
											fontFamily:'Arial',
											color:Colors.teal.shade100,
											fontSize:10.0,
											letterSpacing:3,
											fontWeight: FontWeight.bold,
											),

									    ),
									SizedBox(
										height:20.0,
										width:100.0,
										child:Divider(
											color:Colors.teal.shade100,
										),
									),
									Card(
											margin:EdgeInsets.symmetric(vertical:5.0, horizontal:20.0),
											color:Colors.white,
											child: ListTile(
												leading:Icon(
													Icons.phone,
													color:Colors.teal,
												    ),
												title:Text(
													'(+91) 96852-74607',
													style:TextStyle(
														color:Colors.teal,
														fontFamily: 'Arial',
														fontSize:20.0,
														),
												),
												
												),
											),
											Card(
													margin:EdgeInsets.symmetric(vertical:5.0, horizontal:20.0),
													color:Colors.white,
													child: ListTile(
														leading:Icon(
															Icons.email,
															color:Colors.teal,
														    ),
														title:Text(
															'kgpk2050@gmail.com',
															style:TextStyle(
																color:Colors.teal,
																fontFamily: 'Arial',
																fontSize:20.0,
																),
														    ),
														),
													),
													],
													),
													),
													),
													),
													);
		}
}
