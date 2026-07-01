# RL78/G24 タイマ RD2、タイマ・アレイ・ユニット、コンパレータ連動による TIMER WINDOW出力

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G24 のタイマ RD2、タイマ・アレイ・ユニット（TAU）とコンパレータ（CMP）を連動させて使用する TIMER WINDOW出力について説明します。TIMER WINDOW出力とは、TAU出力（TO02）がロウ・レベルの期間は、CMP出力をロウ・レベルにする機能です。つまり、TAU 出力（TO02）がハイ・レベルの期間のみ、CMPでの電圧検出を有効にできます。RL78/G24 では、タイマRD2 出力の有効エッジを TAU0 のチャネル 0 のスタート・トリガに設定することが可能です。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.10.00 |
| e2 studio | 2023-07 (23.7.0) |
| CC-RL | V1.12.01 |
| IAR Embedded Workbench | V4.21.1 |
| IAR Compiler | V4.21.1 |
| Smart Configurator | V1.7.0 |
| BSP | V1.60 |

## ハードウェア構成
- RL78/G24 Fast Prototyping Board (RTK7RLG240C00000BJ)

## 適用可能デバイス
- RL78/G24

## APNリンク
[RL78/G24 タイマ RD2、タイマ・アレイ・ユニット、コンパレータ連動による TIMER WINDOW出力](https://www.renesas.com/ja/document/apn/rl78g24-timer-window-output-using-timer-rd2-timer-array-unit-and-comparato-rev100)
