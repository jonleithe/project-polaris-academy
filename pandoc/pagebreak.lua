-- Convert an invisible Markdown comment into a LaTeX page break.
function RawBlock(block)
  if block.format == "html"
      and block.text:match("^<!%-%-%s*pagebreak%s*%-%->$") then
    return pandoc.RawBlock("latex", "\\newpage")
  end
end
