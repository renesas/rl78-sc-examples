# RL78/G22 A/Dコンバータ (ソフトウエア・トリガ、スキャン・モード)

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G22のA/Dコンバータをソフトウエア・トリガ、スキャン・モード、連続変換モードで使用する方法を説明します。複数のアナログ入力端子の電圧をデジタル値に変換する例を示します。変換結果はデータ処理後に内蔵RAMへ格納されます。サンプルコードではHALTモードで変換完了を待機し、割り込みで処理します。チャネルの自動切り替え動作も説明されています。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | 9.11.04 |
| e2 studio | V2024-01 (24.1.0) |
| CC-RL | V1.13.00 |
| IAR Embedded Workbench | V5.10.3 |
| IAR Compiler | V5.10.3 |
| Smart Configurator | V1.10.0 |
| BSP | V1.62 |

## ハードウェア構成
- RL78/G22 Fast Prototyping Board
- 外部アナログ入力信号源

## 適用可能デバイス
- RL78/G22

## APNリンク
[RL78/G22 A/Dコンバータ (ソフトウエア・トリガ、スキャン・モード)](https://www.renesas.com/ja/document/apn/rl78g22-ad-converter-software-trigger-and-scan-conversion-modes-rev110)
