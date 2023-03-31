import wx

class JanelaPrincipal(wx.Frame):
    def __init__(self, parent=None, title="Blackjack"):
        super().__init__(parent=parent, title=title)
        self.InitUI()

    def InitUI(self):
        self.SetSize((500, 300))
        self.SetTitle("Blackjack - Carteira")
        self.Centre()

class JanelaPrincipal(wx.Frame):
    def __init__(self, parent=None, title="Blackjack"):
        super().__init__(parent=parent, title=title)
        self.InitUI()

    def InitUI(self):
        self.panel = wx.Panel(self)
        self.SetSize((500, 300))
        self.SetTitle("Blackjack - Carteira")
        self.Centre()

class JanelaPrincipal(wx.Frame):
    def __init__(self, parent=None, title="Blackjack"):
        super().__init__(parent=parent, title=title)
        self.InitUI()

    def InitUI(self):
        self.panel = wx.Panel(self)
        self.adicionar_aposta_button = wx.Button(self.panel, label="Adicionar Aposta")
        self.SetSize((500, 300))
        self.SetTitle("Blackjack - Carteira")
        self.Centre()

class JanelaPrincipal(wx.Frame):
    def __init__(self, parent=None, title="Blackjack"):
        super().__init__(parent=parent, title=title)
        self.InitUI()

    def InitUI(self):
        self.panel = wx.Panel(self)
        self.adicionar_aposta_button = wx.Button(self.panel, label="Adicionar Aposta")
        self.adicionar_aposta_button.Bind(wx.EVT_BUTTON, self.OnAdicionarAposta)
        self.imprimir_apostas_button = wx.Button(self.panel, label="Imprimir Apostas")
        self.imprimir_apostas_button.Bind(wx.EVT_BUTTON, self.OnImprimirApostas)
        self.sair_button = wx.Button(self.panel, label="Sair")
        self.sair_button.Bind(wx.EVT_BUTTON, self.OnSair)
        self.SetSize((500, 300))
        self.SetTitle("Blackjack - Carteira")
        self.Centre()

    def OnAdicionarAposta(self, event):
        pass

    def OnImprimirApostas(self, event):
        pass

    def OnSair(self, event):
        self.Close()

if __name__ == '__main__':
    app = wx.App()
    frame = App(None, title='Blackjack Carteira')
    frame.Show()
    app.MainLoop()

