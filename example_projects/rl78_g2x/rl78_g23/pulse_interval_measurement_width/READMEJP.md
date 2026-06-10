# RL78/G23 タイマ・アレイ・ユニット (パルス間隔測定: 幅)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23のタイマ・アレイ・ユニット（TAU）を用いたパルス幅測定機能について説明します。タイマ入力端子で立ち上がりエッジおよび立ち下がりエッジを検出し、ハイ・レベル幅とロウ・レベル幅を測定します。取得したタイマ値をもとにパルス幅を算出し、測定結果は内蔵RAMに格納されます。エッジ判定と割り込み処理を組み合わせた測定例です。

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
[RL78/G23 タイマ・アレイ・ユニット (パルス間隔測定: 幅)](https://www.renesas.com/ja/document/apn/rl78g23-timer-array-unit-pulse-interval-measurement-width-rev100)
