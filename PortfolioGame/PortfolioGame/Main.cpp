#include <DXLib.h>
#include "Scene/SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        return -1;        // エラーが起きたら直ちに終了
    }

    //ウィンドウモード設定
    ChangeWindowMode(true);
    SetGraphMode(1920, 1080, 32);

    //描画先キャンバスを裏キャンバスに指定
    SetDrawScreen(DX_SCREEN_BACK);

    //ESCキーが押されるかエラーが出るまでループします
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //シーンの実行
        SceneManager::Instance()->Execute();
    }

    // ＤＸライブラリ使用の終了処理
    DxLib_End();

    // ソフトの終了
    return 0;
}