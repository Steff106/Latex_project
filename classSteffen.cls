% Latex Doku
% https://de.wikibooks.org/wiki/LaTeX-Kompendium:_Baukastensystem

\ProvidesClass{classSteffen}

\LoadClassWithOptions{scrreprt}

% Übersetzung spezifischer Befehle (z.B. "Inhaltsverzeichnis" statt "table of contents", "Kapitel" statt "chapter"), Silbentrennung, Sonderzeichen
\usepackage[ngerman]{babel}

% T1-Version der Computer-Modern-Schriftfamilie (CM): Umlaute
\usepackage[T1]{fontenc}

% Zeichencodierung (sollte für Windows und UNIX geeignet sein)
\usepackage[utf8]{inputenc}

% Für Anführungszeichen
\usepackage{csquotes}

% Kopf- /Fußzeile
\usepackage[automark,footsepline,headsepline,plainfootsepline,plainheadsepline]{scrlayer-scrpage}

% Seitenlayout anpassen
\usepackage[paper=a4paper,left=30mm,right=20mm,top=30mm,bottom=28mm]{geometry}

% Verzeichnise ändern
%\usepackage{tocloft}
%\usepackage{tocbasic}

% für das importieren von sections aus eigenen Dateien benötigt (\import)
\usepackage{import}

% lädt die skalierbare Latin‑Modern‑Schriften (oft besser bei Fehler mit font expansion)
\usepackage{lmodern}

%u. a. schönere Überschriftenart
\usepackage{helvet} 

%für Programmcode im text
\usepackage{listings} 

% verbesserter Randausgleich
\usepackage[final]{microtype}

% für Abkürzungsverzeichnis
\usepackage{acronym} 

% Zum Vergleich von Strings benötigt
\usepackage{pdftexcmds}
\usepackage{xstring}

% Zeilenabstand ändern (onehalfspacing --> 1,5)
\usepackage[onehalfspacing]{setspace}

% Brüche für Einheiten
\usepackage{units}

% Ändern der Hintergrundfarbei bei Definitionen oder Formeln und Tabellen
\usepackage[table,xcdraw]{xcolor}

% bestehende pdf/svg Dateien einbinden
\usepackage{pdfpages}
%\usepackage{svg}

% Verlinkung auf Bilder gehen an Anfang vom Bild nicht auf Beschriftung
\usepackage{caption} 

% für Theorem Umgebung --> Farbig hinterlegen
\usepackage{shadethm}

% um Umgebungen mit dem Parameter H zu setzen, H steht für genau hier
\usepackage{float}

% für schöne Tabellen und Tabellen über mehrere Seiten
\usepackage{booktabs}
\usepackage{longtable}

% eingebundene Bilder bearbeiten mit Tex commands
%\usepackage[abs]{overpic}
%\usepackage{pict2e}

\usepackage{mathtools}
\usepackage{graphicx}

\usepackage{amsmath}
% \usepackage{colortbl}
\usepackage{enumitem}
\usepackage{esvect}
%\usepackage{parskip}
\usepackage{nameref}
\usepackage{relsize}
\usepackage{subfigure}
\usepackage{multicol}
\usepackage{wasysym}