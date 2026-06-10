# RL78/G23 タイマ・アレイ・ユニット (パルス間隔測定: 周期)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のタイマ・アレイ・ユニット（TAU）を用いたパルス間隔測定機能について説明します。タイマ入力端子で有効エッジを検出し、そのときのタイマカウント値をキャプチャしてパルス間隔を求めます。測定結果は内蔵RAMに格納され、繰り返し測定処理が可能です。割り込みベースでのキャプチャ動作と測定例を示しています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.06.00 |
| e2 studio | V2021-07 (21.7.0) |
| CC-RL | V1.10.00 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.1.0 |
| BSP | V1.11 |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- パルス信号

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 タイマ・アレイ・ユニット (パルス間隔測定: 周期)](https://www.renesas.com/ja/document/apn/rl78g23-timer-array-unit-pulse-interval-measurement-period-rev100)
