type browserTracing

type config = {
  dsn: string,
  tracesSampleRate: float,
  integrations: array<browserTracing>,
}

@bs.module("@sentry/react") external init: config => unit = "init"
@bs.module("@sentry/tracing") @bs.scope("Integrations") @bs.new
external makeTracing: unit => browserTracing = "BrowserTracing"

let startSentry = () => {
  switch Environment.dsn {
  | None => ()
  | Some(dsn) => {
      let params = {
        dsn: dsn,
        tracesSampleRate: 1.0,
        integrations: [makeTracing()],
      }

      init(params)
    }
  }
}
