/*
Autor: Carlos Daniel Santiago López
todos los derechos reservados
*/
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
int main()
{	
int op1,sb1,sb2,op2,sb3,sb4,sb5,sb6,sb7,sb8,sb9,sb10;
FILE *a;   //Apunta a la carpeta que definiremos
FILE *z;
system("cls");		//limpia la pantalla
printf("\t!!!Bienvenido al Sistema Complementario de Transformacion de Rumbos!!!\n");			//Este parte da la bienvenida al programa
Sleep(2000);
do
{
	system("cls");
	printf("\nSeleccione la opci%cn que desea realizar\n",162);
	printf("1)Transformador de rumbos de azimutal a cuadrantes\n2)Transformador de rumbos de cuadrantes a azimutal\n3)Salir\n");
	printf("NOTA:Los datos que proporciona el programa son con la supocicion de que la medida fue realizada con pinula a la derecha\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		scanf("%d",&op1);
		switch(op1)
		{
			case 1:
				system("cls"); 
				do
				{		
					setbuf(stdin, NULL);	//Limpia basuara del teclado 
					printf("\n\t\tTransfromaci%cn de rumbos azimutal a cuadrantes\n\n",162);
					printf("Introduzca su rumbo con valores v%clidos del 0%c al 360%c\n",160,167,167);
					printf("Para salir igrese el n%cmero 1000\nPara limpiar la carpeta ingrese el n%cmero 2000\n",163,163);
					scanf("%d",&sb1);
					z = fopen ("Azi-cuad.txt","a+t"); //abre el archivo, indica que se va añadir texto a ese archivo
					if(z == NULL) 
					{
						printf("No se a podido abrir el archivo\n");
					}	
					else
					{
						if (sb1>360 && sb1!=1000 &&	sb1!=2000)
						{
							printf("El rumbo es inv%clido\n",160);
							Sleep(2000);		//Espera un timpo para continuar
							system("cls");
						}		
						else
						{	
							if (sb1<0)
							{
								printf("El rumbo es inv%clido\n",160);
								Sleep(2000);      
								system("cls");
							}
							else
							{
								if (sb1==0)
								{
									sb2=sb1;
									system("cls");					       
									printf("El rumbo es %c%cN\n",sb2,167);
									fprintf(z,"N%d\n", sb2);	//Imprime en el archivo seleccionado 
								}
								else
								{
									if (sb1<=90)
									{
										sb2=sb1;
										system("cls");
										printf("El rumbo es:N%d%cE\n",sb2,167);
										fprintf(z,"N%dE\n", sb2);
					     			}
									else
									{	
										if (sb1==180)
										{
											sb2=sb1-180;
											system("cls");
											printf("El rumbo es:%c%cS\n",sb2,167);
											fprintf(z,"S%d\n", sb2);
										}
										else
										{	
											if (sb1<180)
											{	 
												system("cls");	
												sb2=180-sb1;
												printf("El rumbo es S%d%cE\n",sb2,248);
												fprintf(z,"S%dE\n", sb2);
											}
											else
											{
												if (sb1<=270)
												{
													system("cls");
													sb2=sb1-180;
													printf("El rumbo es S%d%cW\n",sb2,248);
													fprintf(z,"S%dW\n", sb2);
												}
												else
												{
													if (sb1==360)
													{
														system("cls");
														sb2=360;
														printf ("El rumbo es %d%cN\n",sb2,248); 
														fprintf(z,"N%d\n", sb2);
													}
													else
													{	
														if (sb1<360)
														{
															system("cls");
															sb2=360-sb1;
															printf("El rumbo es N%d%cW\n",sb2,248);
															setbuf(stdin, NULL);
															fprintf(z,"N%dW\n", sb2);
														}
														else 
														{
															printf("La carpeta fue limpiada\n");
														}
													}										
												}
											}
										}
									}			
								}
							}
						}	
						printf("Tus datos estan almacenados en el blok de notas llamado:-Azi-cuad-\n");
						printf("Nota:Si quieres ingresar datos de otra medici%cn no olvides primero copiar el archivo -Azi-cuad- para que no pierdas los datos y luego ingresar 2000\n",162);
					}	
					fclose(z);
					if(sb1==2000)
					{
						z = fopen ("Azi-cuad.txt","w+t");
						fprintf(z,"", sb2);
					}	
					fclose(z);
				}while(sb1!=1000); 
				break;
			case 2:
				do
				{
					system("cls"); 
					setbuf(stdin, NULL);
					printf("\t\tTransformaci%cn de rumbos en cuadrantes a azimutal\n\n",162);
					printf("Selecciona el cuadrante de tu rumbo\n");
					printf("1)NE\n2)SE\n3)SW\n4)NW\n5)Limpiar la carpeta\n6)Salir\n");
					printf("Tus datos estan almacenados en el blok de notas llamado:-Cuad-azi-\n");
					printf("Nota:Si quieres ingresar datos de otra medici%cn no olvides primero copiar el archivo -Azi-cuad- para que no pierdas los datos\n",162);
					scanf("%d",&op2);
					switch (op2)
					{
						case 1:
							system("cls");
							do
							{	
								setbuf(stdin, NULL);
								z = fopen ("Cuad-azi.txt","a+t");
								printf("\t\tCuadrante NE\n\n");
								printf("Ingresa el valor de tu cuadrante con valores v%clidos del 0%c al 90%c\n",160,248,248);
								printf("Para salir ingrese el numero 1000\n");
								scanf("%d",&sb3);
								if(sb3<=90 && sb3>=0) 
								{		
									system("cls");
									printf("El rumbo es:%d%c\n",sb3,248);
									fprintf(z,"%d\n", sb3);
								}
								else
								{
									if(sb3==1000)
									{}
									else
									{
									printf("El rumbo es inv%clido\n",160);
									Sleep(2000);
									system("cls");
									}
								}	
								fclose(z);
							}while (sb3!=1000);
							break;
						case 2:
							system("cls");
							do
							{	
								setbuf(stdin, NULL);
								z = fopen ("Cuad-azi.txt","a+t");
								printf("\t\tCuadrante SE\n\n");
								printf("Ingresa el valor de tu cuadrante con valores v%clidos del 0%c al 90%c\n",160,248,248);
								printf("Para salir ingrese el numero 1000\n");
								scanf("%d",&sb4);						
								if(sb4<=90 && sb4>=0)
								{
									system("cls");
									sb5=180-sb4;
									printf("El rumbo es %d%c\n",sb5,248);
									fprintf(z,"%d\n", sb5);
								}
								else
								{
									if(sb4==1000)
									{}
									else
									{
									printf("El rumbo es inv%clido\n",160);
									Sleep(2000);
									system("cls");
									}
								}	
								fclose(z);
							}while(sb4!=1000);  
							break;
						case 3:
							system("cls");
							do
							{	
								setbuf(stdin, NULL);
								z = fopen ("Cuad-azi.txt","a+t");
								printf("\t\tCuadrante SW\n\n");
								printf("Ingresa el valor de tu cuadrante con valores v%clidos del 0%c al 90%c\n",160,248,248);
								printf("Para salir ingrese el numero 1000\n");
								scanf("%d",&sb6);
								if(sb6<=90 && sb6>=0)
								{
									system("cls");
									sb7=180+sb6;
									printf("El rumbo es %d%c\n",sb7,248);
									fprintf(z,"%d\n", sb7);
								}
								else
								{
									if(sb6==1000)
									{}
									else
									{
									system("cls");
									printf("El rumbo es inv%clido\n",160);
									Sleep(2000);
									}
								}
								fclose(z);
							}while (sb6!=1000);
							break;
						case 4:
							system("cls");
							do
							{
								setbuf(stdin, NULL);
								z = fopen ("Cuad-azi.txt","a+t");
								printf("\t\tCuadrante NW\n\n");
								printf("Ingresa el valor de tu cuadrante\n");
								printf("Para salir ingrese el numero 1000\n");
								scanf("%d",&sb8);
								if(sb8<=90 && sb8>=0)
								{			
									system("cls");
									setbuf(stdin, NULL);
									sb9=360-sb8;
									printf("El rumbo es %d%c\n",sb9,248);
									fprintf(z,"%d\n", sb9);
								}
								else
								{
									if(sb8==1000)
									{}
									else
									{
									printf("El rumbo es inv%clido\n",160);
									Sleep(2000);
									system("cls");
									}
								}
								fclose(z);
							}while (sb8!=1000);
							fclose(z);
							break;
						case 5:
							z = fopen ("Cuad-azi.txt","w+t");
							fprintf(z,"", sb10);	
							fclose(z);
							printf("La carpeta fue limpiada");
							break;
						case 6:
							printf("vuelve pronto (:\n");
							break;
						default:
							printf("opci%on inv%clida\n",162,160);
							break;
					}
				}while(op2!=6);
				break;
		}					
}while(op1!=3);	//cierra los do while
	return 0;
}