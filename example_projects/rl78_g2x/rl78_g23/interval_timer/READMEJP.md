# RL78/G23 タイマ・アレイ・ユニット (インターバル・タイマ)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のタイマ・アレイ・ユニット（TAU）によるインターバル・タイマ機能の使用方法を説明しています。タイマ割り込みごとにLEDを反転させる動作を実装し、一定周期での制御方法を示します。さらに、スイッチの押下回数に応じてタイマ周期を変更する処理も含まれています。外部割り込みとタイマ割り込みを組み合わせた応用例となっています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.05.00 |
| e2 studio | V2021-04 (21.4.0) |
| CC-RL | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.0.1 |
| BSP | V1.00 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LED
- スイッチ

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 タイマ・アレイ・ユニット (インターバル・タイマ)](https://www.renesas.com/ja/document/apn/rl78g23-timer-array-unit-interval-timer)
