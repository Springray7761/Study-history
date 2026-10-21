import type { Register } from 'claude-code'

// 每一輪都要把整段對話重送一次，對話越長、每輪越耗用量
const SOFT = 100_000   // 提醒：可以準備開新對話
const HARD = 200_000   // 建議：現在開新對話
let warned = 0

export const register: Register = on => {
  on('turn.complete', async ($, e, next) => {
    const r = await next(e)
    try {
      const { context } = await $.session.usage()
      const t = context.tokens ?? 0
      const k = Math.round(t / 1000)
      const lvl = t >= HARD ? 2 : t >= SOFT ? 1 : 0
      $.ui.status(`對話長度 ${k}k tokens${context.percent != null ? `（${context.percent}%）` : ''}${lvl === 2 ? '｜建議開新對話' : lvl === 1 ? '｜偏長' : ''}`)
      if (lvl > warned) {
        warned = lvl
        $.ui.toast(lvl === 2
          ? `對話已 ${k}k tokens：建議現在開新對話，開頭請 Claude 讀 project_summary.md 等檔案接續。`
          : `對話已 ${k}k tokens：告一段落時可以開新對話，比較省用量。`)
      }
    } catch { /* 用量讀不到就不顯示 */ }
    return r
  })
}
