# RL78/G22 32 ビット・インターバル・タイマ (8 ビット・カウンタ・モード)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、32ビット・インターバル・タイマの8ビット・カウンタ・モードの使用方法を説明します。タイマ割り込み時にコンペア一致検出フラグに応じてLED表示を反転します。また、スイッチ押下回数に応じてタイマ割り込み周期を変更します。外部割り込みとタイマ割り込みを組み合わせた動作制御を示します。RL78/G22での実装例をサンプルコードとして提供します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | E8.11.00 |
| e2studio | V2023-07 |
| CC-RL | V1.13.00 |
| IAR | V5.10.3 |
| SC | V1.11.0 |
| BSP | V1.62 |

## ハードウェア構成
- RL78/G22-64p Fast Prototyping Board
- LED（LED1～LED4）
- スイッチ

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 32 ビット・インターバル・タイマ (8 ビット・カウンタ・モード)](https://www.renesas.com/ja/document/apn/rl78g22-ad-converter-software-trigger-and-scan-conversion-modes-rev110)
