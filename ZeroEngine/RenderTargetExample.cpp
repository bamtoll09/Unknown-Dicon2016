﻿#include "stdafx.h"
#include "RenderTargetExample.h"

/*--------------------------------------------------------------------------------*/
//
//							생성자 부분에서 변수 초기화
//
/*--------------------------------------------------------------------------------*/
RenderTargetExample::RenderTargetExample() {
	m_pSprite = new ZeroSprite("Texture/Second.png");
	PushScene(m_pSprite);
}
/*--------------------------------------------------------------------------------*/
//
//										소멸자
//
/*--------------------------------------------------------------------------------*/
RenderTargetExample::~RenderTargetExample() {
}
/*--------------------------------------------------------------------------------*/
//
//							Update 함수에서는 기능을 검사
//
/*--------------------------------------------------------------------------------*/
void RenderTargetExample::Update(float eTime) {
	ZeroIScene::Update(eTime);
}
/*--------------------------------------------------------------------------------*/
//
//							Render함수에서는 그리기만 한다.
//
/*--------------------------------------------------------------------------------*/
void RenderTargetExample::Render() {
	ZeroIScene::Render();

	//화면에 그림을 그리는게 아니라
	//render라는 이름의 텍스쳐에 그림을 그린다.
	//이름은 자유자재로 바꿀수 있다.
	//Begin과 End 사이에 그린다.
	ZeroRTMgr("render")->Begin();
	m_pSprite->Render();
	ZeroRTMgr("render")->End();

	//render페이지의 텍스쳐를 화면에 그린다.
	//이거 주석처리하면 안보임
	ZeroRTMgr("render")->Render();
}
