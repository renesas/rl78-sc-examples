# RL78/L23 LCD表示（温度表示デモ）

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/L23 の LCDコントローラ／ドライバで LCDパネルとの制御およびサンプルコードの動作を説明します。サンプルコードではRL78/L23 の LCDコントローラ／ドライバを使用し、温度表示の使用例を示します。ユーザスイッチの押下とタッチボタンのタッチ検出により温度データの調整を行い、調整後の温度データを表示します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.14.00 |
| e2 studio | Version 2025-07 |
| CC-RL | V1.15.01 |
| IAR Embedded Workbench | V5.20.1 |
| IAR Compiler | V5.20.1 |
| Smart Configurator | V1.14.0 |
| BSP | V1.91 |

## ハードウェア構成
- RL78/L23 Fast Prototyping Board (RTK7RLL230S00001BJ)
- Varitronix VIM-878-DP-FC-S-LV
- タッチボタン1
- タッチボタン2
- ユーザスイッチ
- LED1
- LED2

## 適用可能デバイス
- RL78/L23

## APNリンク
[RL78/L23 LCD表示（温度表示デモ）](https://www.renesas.com/ja/document/apn/rl78l23-lcd-display-temperature-display-demo-rev111)
