#include <time.h>//�����p
#include <stdlib.h>
#include <stdio.h>
#include "func.h"

unsigned short int cardScore[TYPE][CARDNUMBER];//�J�[�h�̒l�������Ă���
unsigned short int card[TYPE][CARDNUMBER];//�R�D
unsigned short int haveCard[PLAYER][CARDDEAL];//me��com�̃J�[�h�̕ێ�����ϐ�

void funcMain(){//func���C��

	unsigned int flag = 0;//��񏈗����邽�ߗp
	int i,j;//�񂷗p

	if(flag == 0){
		srand((unsigned int)time(NULL));//rand()�֐����g��
		flag = 1;
	}

	cardScoreInitialize();	//�J�[�h�̏�����������

	for(i=0;i<PLAYER;i++){//�l������
		for(j=0;j<FIRSTDEAL;j++){//2�����n���ŏ��̏���
			deal(i,j);	//�J�[�h��z��
		}
	}
	
	viewCard(ME);

	//�f�o�b�N
	draw();

}

void cardScoreInitialize(){//�J�[�h�̃X�R�A�̏�����
	int i,j; //�񂷗p

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
void deal(int player,int cardDeal){//�N���������ƁA�����ڂ��������������Ƃ��Ďg���֐�
	
	int type,cardNumber;
	
	while(1){

		//�����_���Ŏ擾
		type = rand()%TYPE;//�J�[�h�̎��
		cardNumber = rand()%CARDNUMBER;//�J�[�h�̔ԍ�

		if(card[type][cardNumber] !=1){//1�������Ă�����

			card[type][cardNumber] = 1;//�J�[�h��������܂���

			haveCard[player][cardDeal] =  (type*CARDNUMBER+cardNumber);//�J�[�h

			break;
		}
	}
}

void viewCard(int player){//�z��ꂽ�J�[�h���ǂ�ȃX�R�A�Ȃ̂�������

	int j = 0;//�莝���J�[�h���񂷗p
	
	int type,cardNumber;//�񎟌��֐��ɖ߂�
	int value =0;//���v�����p

	while(haveCard[player][j]!=0){//�J�[�h�̖���������
		//1�����z�񂩂�s�Ɨ�𒲂ׂ�
		cardNumber = haveCard[player][j] %13;//�s
		type= haveCard[player][j] /13;//��

		value +=cardScore[type][cardNumber];

		if(type ==HART){
			printf("%d���ڂ̓n�[�g��%d�ŃX�R�A��%d�ł�\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}else if(type ==SPADE){
			printf("%d���ڂ̓X�y�[�h��%d�ŃX�R�A��%d�ł�\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}else if(type ==TREFOIL){
			printf("%d���ڂ̓N���[�o�[��%d�ŃX�R�A��%d�ł�\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}else if(type ==DIA){
			printf("%d���ڂ̓_�C����%d�ŃX�R�A��%d�ł�\n",j+1,cardNumber+1,cardScore[type][cardNumber]);
		}
		j++;
	}

	//���v�͉��ł�
	printf("���v%d�ł�\n",value);
}
//�f�o�b�N
void draw(){
	
	printf("����1����haveCard[%d][%d] = %d\n",0,0,haveCard[0][0] );
	printf("����2����haveCard[%d][%d] = %d\n",0,1,haveCard[0][1] );
	printf("����3����haveCard[%d][%d] = %d\n",0,2,haveCard[0][2] );
	printf("����1����haveCard[%d][%d] = %d\n",1,0,haveCard[1][0] );
	printf("����2����haveCard[%d][%d] = %d\n",1,1,haveCard[1][1] );
	printf("����3����haveCard[%d][%d] = %d\n",1,2,haveCard[1][2] );
}