		DIFF_OPT_SET(options, SUBMODULE_LOG);
		DIFF_OPT_CLR(options, SUBMODULE_LOG);
		if (!regexec_buf(word_regex, buffer->ptr + *begin,
				 buffer->size - *begin, 1, match, 0)) {
	o->found_changes = 1;

		fprintf(o->file, "%s", ecbdata->header->buf);
		fprintf(o->file, "%s%s--- %s%s%s\n",
		fprintf(o->file, "%s%s+++ %s%s%s\n",
			putc('\n', o->file);
			emit_line(o, context, reset, line, len);
			fputs("~\n", o->file);
			emit_line(o, context, reset, line, len);
		emit_line(o, diff_get_color(ecbdata->color_diff, DIFF_CONTEXT),
		width = term_columns() - options->output_prefix_length;
	if (DIFF_OPT_TST(o, SUBMODULE_LOG) &&
			(!one->mode || S_ISGITLINK(one->mode)) &&
			(!two->mode || S_ISGITLINK(two->mode))) {
				one->oid.hash, two->oid.hash,
	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}

		strbuf_add_unique_abbrev(msg, two->oid.hash, abbrev);
		DIFF_OPT_SET(options, SUBMODULE_LOG);
/*
 * This is different from find_unique_abbrev() in that

	/*
	 * In well-behaved cases, where the abbbreviated result is the
	 * same as the requested length, append three dots after the
	 * abbreviation (hence the whole logic is limited to the case
	 * where abblen < 37); when the actual abbreviated result is a
	 * bit longer than the requested length, we reduce the number
	 * of dots so that they match the well-behaved ones.  However,
	 * if the actual abbreviation is longer than the requested
	 * length by more than three, we give up on aligning, and add
	 * three dots anyway, to indicate that the output is not the
	 * full object name.  Yes, this may be suboptimal, but this
	 * appears only in "diff --raw --abbrev" output and it is not
	 * worth the effort to change it now.  Note that this would
	 * likely to work fine when the automatic sizing of default
	 * abbreviation length is used--we would be fed -1 in "len" in
	 * that case, and will end up always appending three-dots, but
	 * the automatic sizing is supposed to give abblen that ensures
	 * uniqueness across all objects (statistically speaking).
	 */