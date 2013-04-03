#include <time.h>//乱数用
#include <stdlib.h>
#include <stdio.h>
#include "func.h"

unsigned short int cardScore[TYPE][CARDNUMBER];//カードの値が入っている
unsigned short int card[TYPE][CARDNUMBER];//山札
unsigned short int haveCard[PLAYER][CARDDEAL];//meとcomのカードの保持する変数

void funcMain(){//funcメイン

	unsigned int flag = 0;//一回処理するため用
	int i,j;//回す用

	if(flag == 0){
		srand((unsigned int)time(NULL));//rand()関数を使う
		flag = 1;
	}

	cardScoreInitialize();	//カードの初期化をする

	for(i=0;i<PLAYER;i++){//人数分を
		for(j=0;j<FIRSTDEAL;j++){//2枚ずつ渡す最初の処理
			deal(i,j);	//カードを配る
		}
	}
	
	viewCard(ME);

	//デバック
	draw();

}

void cardScoreInitialize(){//カードのスコアの初期化
	int i,j; //回す用

	for(i=0;i<TYPE;i++){
		for(j=0;j<CARDNUMBER;j++){
			switch(j){
				case 0:
					cardScore[i][j] = 11;
				break;
				case 1:
					cardScore[i][j] = 2;
				break;
				case 2:
					cardScore[i][j] = 3;
				break;
				case 3:
					cardScore[i][j] = 4;
				break;
				case 4:
					cardScore[i][j] = 5;
				break;
				case 5:
					cardScore[i][j] = 6;
				break;
				case 6:
					cardScore[i][j] = 7;
				break;
				case 7:
					cardScore[i][j] = 8;
				break;
				case 8:
					cardScore[i][j] = 9;
				break;
				case 9:
					cardScore[i][j] = 10;
				break;
				default:
					cardScore[i][j] = 10;
				break;
			}
		}
	}
}
void deal(int player,int cardDeal){//誰が引くかと、何枚目を引くかを引数として使う関数
	
	int type,cardNumber;
	
	while(1){

		//ランダムで取得
		type = rand()%TYPE;//カードの種類
		cardNumber = rand()%CARDNUMBER;//カードの番号

		if(card[type][cardNumber] !=1){//1が入っていたら

			card[type][cardNumber] = 1;//カードが抜かれました

			haveCard[player][cardDeal] =  (type*CARDNUMBER+cardNumber);//カード

			break;
		}
	}
}

void viewCard(int player){//配られたカードがどんなスコアなのかを見る

	int j = 0;//手持ちカードを回す用
	
	int type,cardNumber;//二次元関数に戻す
	int value =0;//合計入れる用

	while(haveCard[player][j]!=0){//カードの枚数を見る
		//1次元配列から行と列を調べる
		cardNumber = haveCard[player][j] %13;//行
		type= haveCard[player][j] /13;//列

		value +=cardScore[type][cardNumber];

		if(type ==HART){
			printf("%d枚目はハートの%dでスコアは%dです\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}else if(type ==SPADE){
			printf("%d枚目はスペードの%dでスコアは%dです\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}else if(type ==TREFOIL){
			printf("%d枚目はクローバーの%dでスコアは%dです\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}else if(type ==DIA){
			printf("%d枚目はダイヤの%dでスコアは%dです\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}
		j++;
	}

	//合計は何です
	printf("合計%dです\n",value);
}
//デバック
void draw(){
	
	printf("自分1枚目haveCard[%d][%d] = %d\n",0,0,haveCard[0][0] );
	printf("自分2枚目haveCard[%d][%d] = %d\n",0,1,haveCard[0][1] );
	printf("自分3枚目haveCard[%d][%d] = %d\n",0,2,haveCard[0][2] );
	printf("相手1枚目haveCard[%d][%d] = %d\n",1,0,haveCard[1][0] );
	printf("相手2枚目haveCard[%d][%d] = %d\n",1,1,haveCard[1][1] );
	printf("相手3枚目haveCard[%d][%d] = %d\n",1,2,haveCard[1][2] );
}