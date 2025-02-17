#include "AutoPacmanObj.h"

void AutoPacmanObj::Render(float dt,bool t){
	if(t){
		switch(direction){
			case 0:{
				this->sprite->SetFlip(true,false);
				this->x-=speed*dt;
				if(this->x < (float)(col*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5)){
					this->x = (float)(col*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5);
					isMove=false;
				}
				this->sprite->RenderEx( this->x, this->y,0);
			}break;
			case 1:{
				this->x+=speed*dt;
				if(this->x > (float)(col*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5)){
					this->x = (float)(col*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5);
					isMove=false;
				}
				this->sprite->SetFlip(false,false);
				this->sprite->RenderEx( this->x, this->y,0);
			}break;
			case 2:{
				this->y+=speed*dt;
				if(this->y > (float)(row*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5)){
					this->y = (float)(row*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5);
					isMove=false;
				}
				this->sprite->SetFlip(false,false);
				this->sprite->RenderEx( this->x, this->y,240);
			}break;
			case 3:{
				this->y-=speed*dt;
				if(this->y < (float)(row*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5)){
					this->y = (float)(row*DataStorage::SIZE_TEXTURE+DataStorage::MARGIN+DataStorage::SIZE_TEXTURE*0.5);
					isMove=false;
				}
				this->sprite->SetFlip(true,false);
				this->sprite->RenderEx( this->x, this->y,90);
			}break;
			default:this->sprite->Render( this->x, this->y);
		}
	}
	else{
		this->sprite->Render( this->x, this->y);
	}

	if(changeTexture<= DataStorage::WINDOW_FPS*0.5){
		sprite->SetTexture(close);
	}
	else if(changeTexture <=DataStorage::WINDOW_FPS){
		sprite->SetTexture(open);
	}
	else{
		changeTexture=0;
	}
	++changeTexture;
}

AutoPacmanObj::AutoPacmanObj(): direction(-1),speed(DataStorage::AUTOPACMAN_SPEED),isMove(false),changeTexture(0),score(0){
	GameObj::GameObj();
	GameObj::type = 5;
	changeTexture=0;
	XP = 1;
	direction = rand()%4;
}
void AutoPacmanObj::LoadTexture(HGE * _hge){
	open	= _hge->Texture_Load(TEXTURE_AUTOPACMAN_OPEN);
	close	= _hge->Texture_Load(TEXTURE_AUTOPACMAN_CLOSE);
}

void AutoPacmanObj::Setup(){
	XP = 1;
	isMove=false;
	score=0;
	direction = rand()%4;
	speed=DataStorage::AUTOPACMAN_SPEED;
}