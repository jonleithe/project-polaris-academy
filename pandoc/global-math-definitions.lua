-- MathJax accepts document-level \def declarations, while LaTeX display math
-- scopes ordinary \def declarations locally. Promote definitions to \gdef
-- only for LaTeX output and only inside explicitly marked definition blocks.

local function has_class(classes, expected)
  for _, class_name in ipairs(classes) do
    if class_name == expected then
      return true
    end
  end

  return false
end

function Div(div)
  if not FORMAT:match("latex") then
    return nil
  end

  if not has_class(div.classes, "math-definitions") then
    return nil
  end

  return div:walk({
    Math = function(math)
      math.text = math.text:gsub("\\def", "\\gdef")
      return math
    end,
  })
end
