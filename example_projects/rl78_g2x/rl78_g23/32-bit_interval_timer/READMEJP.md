# RL78/G23 32 ビット・インターバル・タイマ (8 ビット・カウンタ・モード)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23の32ビット・インターバル・タイマを8ビット・カウンタ・モードで使用する方法を説明します。タイマ割り込みおよび外部割り込み（INTP0）を利用してLED制御を行います。タイマ割り込み時にコンペア一致検出フラグに応じてLED表示を反転します。また、スイッチの押下回数に応じてタイマの割り込み周期を変更します。外部入力によって分周比を変更する動的制御例を示します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | E8.09.00 |
| e2 studio | V2023-04 (23.4.0) |
| CC-RL | V1.12.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | V1.6.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G23-64p Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED（LED1～LED4）
- スイッチ（SW）

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 32 ビット・インターバル・タイマ (8 ビット・カウンタ・モード)](https://www.renesas.com/ja/document/apn/rl78g23-32-bit-interval-timer-8-bit-counter-mode)
