# RL78/G23 VBAT 端子の使い方

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 の VBAT 端子 (バッテリバックアップ電源) を使用する方法について説明します。VDD電源から電力供給されている期間はリアルタイム・クロックの定周期割り込みを利用してLCDに時刻を表示します。VDD電源からの供給がなくVBAT端子から供給された場合はRTC動作は継続しますがLCD表示は消灯します。電圧検出回路 (LVD0) によりVDD電源供給の有無を判定します。

## 動作確認条件
| 項目 | バージョン情報 |
|----|----|
| CS+ | V8.07.00 |
| e2 studio | V2022-04 (22.4.0) |
| CC-RL | V1.11.00 |
| IAR Embedded Workbench | V4.21.2 |
| IAR Compiler | V4.21.2.2420 |
| Smart Configurator | N/A |
| BSP | N/A |

## ハードウェア構成
- RL78/G23 Fast Prototyping Board (RTK7RLG230CLG000BJ)
- LCDモジュール ACM1602NI-FLW-FBW-M01
- バッテリバックアップ用電源

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 VBAT 端子の使い方](https://www.renesas.com/ja/document/apn/rl78g23-using-vbat-pin)
