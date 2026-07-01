# RL78/G23 中速オンチップ・オシレータ・クロック 周波数補正

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 に搭載されている中速オンチップ・オシレータ・トリミング・レジスタ (MIOTRM) を使用して中速オンチップ・オシレータ (MOCO) の発振クロック周波数を補正する方法を説明します。高速オンチップ・オシレータを使用して中速オンチップ・オシレータの発振周波数のずれを検出し、中速オンチップ・オシレータ・トリミング・レジスタ (MIOTRM) を調整して中速オンチップ・オシレータの発振周波数を 4MHz に近づけます。

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
- スタート・スイッチ
- 補正完了LED

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 中速オンチップ・オシレータ・クロック 周波数補正](https://www.renesas.com/ja/document/apn/rl78g23-middle-speed-chip-oscillator-moco-clock-frequency-correction)
