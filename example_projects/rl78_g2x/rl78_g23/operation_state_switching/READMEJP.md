# RL78/G23 オペレーション・ステートの切り替え

English page is [here](./README.md)

## 概要
本アプリケーションノートでは、RL78/G23 のオペレーション・ステート・コントローラによってオペレーション・ステートを切り替える際のレジスタ設定手順を示します。リセット解除後はHS モードで動作し、ボタン押下によってフラッシュ動作モードを順次切り換えます (HS モード→ LS モード→ LP モード→LS モード→ HS モード。以降、繰り返し) 。

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
- LED1
- LED2
- スイッチ

## 適用可能デバイス
- RL78/G23

## APNリンク
[RL78/G23 オペレーション・ステートの切り替え](https://www.renesas.com/ja/document/apn/rl78g23-operation-state-switching)
