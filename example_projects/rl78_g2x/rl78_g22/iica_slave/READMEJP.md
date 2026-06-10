# RL78/G22 シリアル・インターフェース IICA (スレーブ送受信)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のシリアル・インターフェースIICAを用いたスレーブ送受信の方法を説明します。シングルマスタ構成でのアドレス受信およびデータ送受信動作を対象としています。IIC通信のタイミングやシリアルRAM制御、連続データの読み書き方法について詳しく解説しています。また、動作確認条件とサンプルコードにより実装方法を示しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.11.00 |
| e2 studio | V2024-04 |
| CC-RL | V1.13.01 |
| IAR Embedded Workbench | V5.10.1 |
| IAR Compiler | V5.10.1 |
| Smart Configurator | V1.10.0 |
| BSP | V1.6.2 |

## ハードウェア構成
- RL78/G22-48ピン Fast Prototyping Board

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 シリアル・インターフェース IICA (スレーブ送受信)](https://www.renesas.com/ja/document/apn/rl78g22-serial-interface-iica-slave-transmissionreception-rev100)
