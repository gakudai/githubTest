//関数定義
void funcMain();//funcメイン-

void cardScoreInitialize();//カードのスコアの初期化
void deal(int player,int cardDeal);//カードを渡す処理誰に何枚目をと指定できる
void viewCard(int player);//配られたカードがどんなスコアなのかを見る

void draw();//デバック

#define PLAYER 2	//遊ぶ人数
#define	FIRSTDEAL 2 //最初に引く枚数		
#define ME 0
#define COM 1

//カードの種類
#define CARDDEAL 10		//カードを引く最高の枚数
#define CARDMAX 52	//カードの枚数
#define TYPE 4
#define CARDNUMBER 13 
//♥♠♦♣
#define HART 0
#define SPADE 1
#define TREFOIL 2
#define DIA 3