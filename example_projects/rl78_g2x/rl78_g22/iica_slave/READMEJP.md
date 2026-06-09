# RL78/G22 タイマ・アレイ・ユニット (インターバル・タイマ)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のタイマ・アレイ・ユニット（TAU）のインターバル・タイマ機能の使用方法を説明します。タイマ割り込み発生ごとにLED表示を反転し、さらにスイッチの押下回数に応じてタイマ割り込み周期を変更します。設定方法や動作フロー、サンプルコードを用いて実装方法が詳しく解説されています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2studio | V2023-10 (23.10.0) |
| CC-RL | V1.12.01 |
| IAR | V5.10.1 |
| SC | V1.7.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G22 Fast Prototyping Board
- LED
- スイッチ

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 タイマ・アレイ・ユニット (インターバル・タイマ)](https://www.renesas.com/ja/document/apn/rl78g22-serial-interface-iica-slave-transmissionreception-rev100)
