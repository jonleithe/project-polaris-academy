-- Prefix complete-book chapter titles with the course stored in each note's
-- YAML front matter. The generated book profile supplies one course value for
-- each level-one chapter heading, including an empty value for the preface.

local function markdown_inlines(text)
  local document = pandoc.read(text, "markdown")
  local first_block = document.blocks[1]

  if first_block and (first_block.t == "Para" or first_block.t == "Plain") then
    return first_block.content
  end

  return pandoc.Inlines({ pandoc.Str(text) })
end

local function prefix_course_names(document)
  local configured_courses = document.meta["academy-chapter-courses"]
  if not configured_courses then
    return nil
  end

  local chapter_index = 0
  local transformed = document:walk({
    Header = function(header)
      if header.level ~= 1 then
        return nil
      end

      chapter_index = chapter_index + 1
      local configured_course = configured_courses[tostring(chapter_index)]
      local course = pandoc.utils.stringify(configured_course)
      if course == "" then
        return nil
      end

      local title = markdown_inlines(course)
      table.insert(title, pandoc.Space())
      table.insert(title, pandoc.Str("—"))
      table.insert(title, pandoc.Space())

      for _, inline in ipairs(header.content) do
        table.insert(title, inline)
      end

      header.content = title
      return header
    end,
  })

  transformed.meta["academy-chapter-courses"] = nil
  return transformed
end

return { { Pandoc = prefix_course_names } }
