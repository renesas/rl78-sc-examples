# RL78/G22 タイマ・アレイ・ユニット (PWM出力)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のタイマ・アレイ・ユニット（TAU）を用いたPWM出力機能の使用方法を説明します。TAUチャネルを連動させてPWMを生成し、デューティ比の変更によってLEDの輝度を制御します。タイマ割り込みに基づき一定周期（500ms）でデューティ比更新とLED表示の反転を行います。実装方法や動作フロー、サンプルコードも提供されています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | 8.10.00 |
| e2studio | V2023-10 (23.10.0) |
| CC-RL | V1.12.01 |
| IAR | V5.10.1 |
| SC | V1.7.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G22 Fast Prototyping Board
- 外付けLED
- LED

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 タイマ・アレイ・ユニット (PWM出力)](https://www.renesas.com/ja/document/apn/rl78g22-serial-interface-iica-master-transmissionreception-rev100)
