-- Keybindings
vim.g.mapleader = " "			-- Space as leader key
-- Bootstrap lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git", "clone", "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

-- Basic settings
vim.opt.number = true          -- line numbers
vim.opt.tabstop = 4            -- tab = 4 spaces
vim.opt.shiftwidth = 4
vim.opt.scrolloff = 8          -- keep 8 lines above/below cursor

-- Load plugins
require("lazy").setup("plugins")

-- File tree
vim.keymap.set("n", "<leader>e", ":NvimTreeToggle<CR>")

-- Fuzzy finder
vim.keymap.set("n", "<leader>ff", ":Telescope find_files<CR>")
vim.keymap.set("n", "<leader>fg", ":Telescope live_grep<CR>")

-- Move between split windows
vim.keymap.set("n", "<C-h>", "<C-w>h")
vim.keymap.set("n", "<C-l>", "<C-w>l")
vim.keymap.set("n", "<C-j>", "<C-w>j")
vim.keymap.set("n", "<C-k>", "<C-w>k")
